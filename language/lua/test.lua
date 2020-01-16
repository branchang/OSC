myprint = function(param)
    print("this is print func- ##", param, "##")
end

function add(num1, num2, functionPrint)
    result1 = num1 + num2
    functionPrint(result1)
end
--myprint(10)
--add(2,5,myprint)


function fwrite(fmt, ...)
    return io.write(string.format(fmt, ...))
end

fwrite("runoob\n")
fwrite("%d,%d\n", 1, 2)
-- test.lua 文本末尾注释-- test.lua 文本末尾注释