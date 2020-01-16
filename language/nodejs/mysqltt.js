var mysql = require('mysql');

var connection = mysql.createConnection({
    host:'localhost',
    port:10010,
    user:'ebk',
    password:'H%sL2Vx0M',
    database:'ebooking'
});

connection.connect();

connection.query('select * from ebooking_supplier;', function(error, results, fields){
    if (error) throw error;
    for (var i=0; i<results.length; i++){
        console.log('This solution is :', results[i].name);
    }
});

connection.end();