const express=require("express");
const bodyParser=require("body-parser");
//const request=require("request");
const app=express();

app.use(express.static("public"));
app.get("/",function(req,res){
    res.sendFile(__dirname+"/second.html");
})
app.listen(3000,function(){
    console.log("Server is running on port 3000")
})

app.post("/",function(req,res){
    console.log("post requst recived");
}) 