const exec = require('child_process').execSync;

function compile(req, res) {

  try {
    let cmd;
    if (req.body.type == "editor") {
      // write user code to file
      cmd = `echo "${req.body.code}" > userIn.xy`;
      exec(cmd);
      cmd = `./a.out userIn.xy`;
    } else {
      // compile existing code
      cmd = `./a.out ` + req.body.fileName;
    }

    // compile code
    let out = exec(cmd).toString();
    let data;
    // fetching warnings
    if (out.substring(0, 1) == 'W') {
      out = out.split('$');
      data = JSON.parse(out[out.length - 1]);
      data.warnings = [];
      for (let i = 0; i < out.length - 1; i++) {
        data.warnings.push(out[i]);
      }
    } else {
      data = JSON.parse(out);
      if (data.Error) {
        return res.status(401).send({
          error: data.Error
        });
      }
    }

    // read the output quadruples
    cmd = `cat quadruples.out`
    data.quad = exec(cmd).toString();

    res.status(200).send({
      tree: data.tree,
      quadruples: data.quad,
      warnings: data.warnings
    });

  } catch (error) {
    console.error("Error: " + error);
    res.status(400).send();
  }
}

module.exports = {
  compile
}
