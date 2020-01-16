var xlsx = require('node-xlsx');
var fs = require('fs');

var list = xlsx.parse('度假类型订单.xlsx');

// console.log(list[0]);

for(var rowid in list[0]['data']){
    row = list[0]['data'][rowid];
    // console.log(row);
}

const data = [[1, 2, 3], [true, false, null, 'sheetjs'], ['foo', 'bar', new Date('2014-02-19T14:30Z'), '0.3'], ['baz', null, 'qux']];
var buffer = xlsx.build([{name: "mySheetName", data: data}, {name:"mysheet2", data:data}]);

fs.writeFileSync('./test.xlsx', buffer);

