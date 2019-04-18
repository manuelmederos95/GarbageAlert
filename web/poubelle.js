const token = 'BBFF-EOWLPFC2CqXVz6olPpcMMN1VTydEqU';
const dataJsonFile = 'http://things.ubidots.com/api/v1.6/variables?token='+token;

let data;
var listPoubelle= new Array();
$.getJSON(dataJsonFile, function(json) {
    console.log(json['results']);
    data = json['results'];
    $.each(data, function(index, value) {
        if(value['last_value']['value'] == 1){
            listPoubelle.push(value['label']);
        }
    });
    listPoubelle.forEach(function(item, index, array) {
        $('.listPoubelle').append("<div class=\"poubelle col-sm-4\"><img src = \"poubelle.jpeg\" className = \"img-rounded\" ><h3>"
        +item +
        "</h3></div>");
    });
});