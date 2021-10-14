const express = require("express");
const bodyParser = require("body-parser");
//const request=require("request");
const https = require("https");
const { table } = require("console");
const app = express();

app.use(express.static("public"));
app.use(bodyParser.urlencoded({ extended: true }));
app.get("/", function (req, res) {
    res.sendFile(__dirname + "/first.html");
})
app.get("/second.html", function (req, res) {
    res.sendFile(__dirname + "/second.html");
})

app.post("/", function (req, res) {
    //  res.sendFile(__dirname+"/second.html");
    const name1 = req.body.Name;
    const comment1 = req.body.Comment;
    const rate1 = req.body.stars;
    const email1 = req.body.Email;
    console.log(name1);
    console.log(rate1);
    console.log(comment1);
    console.log(email1);
    var data = {
        members: [
            {
                email_address: email1,
                status: "subscribed",
                merge_fields: {
                    FNAME: name1,
                    FEEDBACK:comment1,
                    RATING:rate1

                }
            }
        ]
    };
    const jsonData = JSON.stringify(data)

    const url = "https://us5.api.mailchimp.com/3.0/lists/6d118701d0"
    options = {
        method: "POST",
        auth: "abhi:c47de6c01ee5c01cf0b86a63d082567f-us5"
    }
    const request = https.request(url, options, function (response) {
        response.on("data", function (data) {
            console.log(JSON.parse(data));
        })
    })

    request.write(jsonData);
    request.end();

    res.sendFile(__dirname + "/first.html");

});

app.listen(process.env.PORT || 3000, function () {
    console.log("Server is running on port 3000")
})

// API KEY
//c47de6c01ee5c01cf0b86a63d082567f-us5
// aud id 6d118701d0.

/*

 responsive
 design website logo
 add social media links
 github icon edit
 second page header
 animation changes in lower part of second web page
 rename all files and folder with proper names
 adding more styling to second page
 hovering effect to show details of each company   

*/