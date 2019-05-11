function compile() {
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function () {
        emptyHtml();
        if (this.readyState == 4 && this.status == 400) {
            document.getElementById("compile-status").innerText = "Failed\n";
        } else if (this.readyState == 4 && this.status == 401) {
            document.getElementById("compile-status").innerText = "Failed\n" + JSON.parse(this.responseText).error;
        } else if (this.readyState == 4 && this.status == 200) {
            let response = JSON.parse(this.responseText);
            let status = document.getElementById("compile-status");
            status.innerText = "Compiled successfully";
            if (response.warnings && response.warnings.length) {
                status.innerText += " with warnings\n"
                response.warnings.forEach(warning => {
                    status.innerText += warning + "\n";
                });
            }
            fillTree(response.tree);
            fillQuadruples(response.quadruples);
        }
    };

    xhttp.open("POST", "/");
    xhttp.setRequestHeader("Content-type", "application/JSON;charset=utf-8");

    let radio = document.getElementsByName("entry-type");
    let body = {};

    if (radio[0].checked == true) {
        body.type = "existing";
        body.fileName = document.getElementById('fileName').value;
        if (body.fileName == "") return;
    } else {
        let textArea = document.getElementById("my_text");
        body.type = "editor";
        body.code = textArea.value;
        if (body.code == "") return;
    }
    xhttp.send(JSON.stringify(body));
}

function fillTable(table, list) {
    let header = document.createElement('li');
    let address = document.createElement('span');
    let parent = document.createElement('span');

    address.textContent = "Address: " + table.table;
    parent.textContent = "Parent: " + table.parent;

    header.appendChild(address);
    header.appendChild(parent);

    list.appendChild(header);

    table.symbols.forEach(symbol => {

        let li = document.createElement('li');
        let name = document.createElement('span');
        let city = document.createElement('span');

        name.textContent = symbol.label;
        city.textContent = symbol.value;

        li.appendChild(name);
        li.appendChild(city);

        list.appendChild(li);
    });
}

function fillTree(tree) {
    let separatorElement = document.getElementById("tree-line");
    separatorElement.innerHTML = "<hr>";
    let treeHeaderElement = document.getElementById("tree-header");
    treeHeaderElement.classList.add("box");
    treeHeaderElement.innerText = "Symbol Table";

    const htmlTree = document.querySelector('#tree');

    let child = htmlTree.firstElementChild;
    while (child) {
        htmlTree.removeChild(child);
        child = htmlTree.firstElementChild;
    }

    tree.forEach(table => {
        let ul = document.createElement('ul');
        fillTable(table, ul);
        htmlTree.appendChild(ul);
    });
}


function handleRadio(radio) {
    let entry = document.getElementById("data-entry");

    if (radio.value == "0") {
        entry.innerHTML = "<input class=\"input\" id=\"fileName\" type=\"text\" placeholder=\"file name\" />";
        let fileNameInput = document.getElementById("fileName");
        let btn = document.getElementById("btn");
        fileNameInput.addEventListener('keypress', function (e) {
            if (e.keyCode == 13) {
                btn.click();
            }
        });
    } else {
        entry.innerHTML = "<div style=\"max-width:700px; margin: auto;\"><textarea placeholder=\"Write code here!\" class=\"text_edit\" id=\"my_text\"></textarea></div>";
    }
}

function emptyHtml() {
    let compilerOut = document.getElementById('tree-line');
    let child = compilerOut.firstElementChild;
    compilerOut.innerHTML = "";

    compilerOut = document.getElementById('tree-header');
    compilerOut.classList.remove("box");
    compilerOut.innerText = "";

    compilerOut = document.getElementById('tree');
    child = compilerOut.firstElementChild;
    while (child) {
        compilerOut.removeChild(child);
        child = compilerOut.firstElementChild;
    }

    compilerOut = document.getElementById('quad-line');
    compilerOut.innerHTML = "";

    compilerOut = document.getElementById('quad-header');
    compilerOut.classList.remove("box");
    compilerOut.innerText = "";

    compilerOut = document.getElementById('quad');
    compilerOut.classList.remove("box");
    compilerOut.innerText = "";
}

function defaultRadio() {
    document.getElementById("def-radio").checked = true;
    let entry = document.getElementById("data-entry");
    entry.innerHTML = "<input class=\"input\" id=\"fileName\" type=\"text\" placeholder=\"file name\" />";

    let fileNameInput = document.getElementById("fileName");
    let btn = document.getElementById("btn");
    fileNameInput.addEventListener('keypress', function (e) {
        if (e.keyCode == 13) {
            btn.click();
        }
    });
}

function fillQuadruples(quadruples) {
    let separatorElement = document.getElementById("quad-line");
    separatorElement.innerHTML = "<hr>";

    let quadHeaderElement = document.getElementById("quad-header");
    quadHeaderElement.classList.add("box");
    quadHeaderElement.innerText = "Quadruples";

    let quadElement = document.getElementById("quad");
    quadElement.classList.add("box");
    quadElement.innerText = quadruples;
}
