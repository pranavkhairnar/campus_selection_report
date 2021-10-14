var bodyParser = require('body-parser');
var express = require('express');
var app = express();
const name_of_company = [];
const n_1718 = [];
const n_1819 = [];
const n_1920 = [];
const n_2021 = [];
const s_1718 = [];
const s_1819 = [];
const s_1920 = [];
const s_2021 = [];

var object1;

var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";
var company;
app.use(express.static(__dirname + '/'));
app.use(bodyParser.urlencoded({
  extend: true
}));
app.engine('html', require('ejs').renderFile);
app.set('view engine', 'html');
app.set('views', __dirname);


MongoClient.connect(url, function (err, db) {
  if (err) throw err;
  var dbo = db.db("reports");
  dbo.collection("year_data").find({}, {
    projection: {}
  }).toArray(function (err, result) {
    if (err) throw err;
    
    console.log(result);
    var p1 = "-";
    for (let i = 1; i < 241; i++) {
     

      if (result[i - 1].Salary1718 == "-1") {
        result[i - 1].Salary1718=p1;
        result[i-1].N1718=p1;
     
      }
    



      if (result[i - 1].Salary1819 == "-1") {
        result[i - 1].Salary1819=p1;
        result[i-1].N1819=p1;
      }
    



      if (result[i - 1].Salary1920 == "-1") {
        result[i - 1].Salary1920=p1;
        result[i-1].N1920=p1;
      }
     

      if (result[i - 1].Salary2021 == "-1") {
        result[i - 1].Salary2021=p1;
        result[i-1].N2021=p1;
      }
    

    }
    object1 = result;


    db.close();
  });
});

app.get('/', function (req, res) {
  /*
  res.render('index.ejs', {
    object1: object1
  });
  */
  res.send(object1);
});
app.listen(3000, function () {
  console.log("Server is started");
});