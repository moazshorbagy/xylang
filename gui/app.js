var express = require('express');
var cors = require('cors');
var utility = require('./utility');
var cookieParser = require('cookie-parser');

var app = express();

app.use(cors({ credentials: true, origin: true }));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static('public'));

//to allow the server to have control over GET, POST, ...
app.use(function (req, res, next) {
    res.setHeader("Access-Control-Allow-Origin", "*");
    res.setHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE");
    res.setHeader("Access-Control-Allow-Headers", "Content-Type");
    res.setHeader("Access-Control-Allow-Credentials", true);
    next();
});

app.get('/', (req, res) => { res.sendFile(__dirname + '/public/view.html') });
app.post('/', utility.compile);

app.listen(3000, function () {
    console.log('listening for requests on port 3000');
});
