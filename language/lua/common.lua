function t_for()
    a = {"one", "two", "three"}
    for i, v in ipairs(a) do
        print(i, v)
    end
    days = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}  
    for i,v  in ipairs(days) do 
        print(v)
    end
end

function t_if()
    if 1 then
        print("yes is 1")
    end
    if 0  then
        print("yes is and 0")
    end
    if nil then
        print("yes is nil")
    end

    if false then
        print("yes is false")
    end
    local a = 8
    if a >10 then
        print("big then 10")
    elseif a <5 then
        print("smail 5")
    else
        print("mid")
    end
end

function max(num1, num2)
    if (num1>num2) then
        return num1
    elseif (num1 < num2) then
        return num2
    else
        return num1
    end
end

function sfind(s1, s2)
    s, e = string.find(s1,s2)
    print(s,e)
    return s, e
end


-- 可变参数
function add(...)
    local s = 0
    for i,v in ipairs{...} do
        s = s + v
    end
    return s
end

-- 运算符
function  t_operator()
    -- 不等于
    local a = 10
    if a~=11 then
        print("a not equal 10")
    end
    -- 取长度
    local s1 = "hello world"
    print("s1 len", #s1)
    -- 字符拼接
    local s2 = s1.." zhr test"
    print(s2)
end

-- 字符串操作主要是string库

-- 数组
function t_array()
    -- 一维数组
    one_array = {"Lua", "Tutorial"}
    print("类型是:",type(one_array))
    for i in ipairs(one_array) do
        print(one_array[i])
    end

    -- 多维数组
    array = {}
    for i=1,3 do
    array[i] = {}
        for j=1,3 do
            array[i][j] = i*j
        end
    end

    for i=1,3 do
        for j=1,3 do
           print(array[i][j])
        end
    end
end


-- table 操作

function t_table()
    -- 简单的 table
    mytable = {}
    print("mytable 的类型是 ",type(mytable))

    mytable[1]= "Lua"
    mytable["wow"] = "修改前"
    print("mytable 索引为 1 的元素是 ", mytable[1])
    print("mytable 索引为 wow 的元素是 ", mytable["wow"])

    -- alternatetable和mytable的是指同一个 table
    alternatetable = mytable

    print("alternatetable 索引为 1 的元素是 ", alternatetable[1])
    print("mytable 索引为 wow 的元素是 ", alternatetable["wow"])

    alternatetable["wow"] = "修改后"

    print("mytable 索引为 wow 的元素是 ", mytable["wow"])

    -- 释放变量
    alternatetable = nil
    print("alternatetable 是 ", alternatetable)

    -- mytable 仍然可以访问
    print("mytable 索引为 wow 的元素是 ", mytable["wow"])

    mytable = nil
    print("mytable 是 ", mytable)
end

function t_table2()
    t1 = {2,4,language = "lua",lua = "aa",10}
    print(t1[1],t1[2])
    print(t1['language'])
    print(t1[3])
end

function t_print(i,v)
    print(i,v)
end

function t_table3()
    local mm = {}
    mm.myfunc = t_table2
    mm.myfunc()
    local array = {"x", "y", "z"}
    print("num:",#array)
    table.insert(array, 2, "aa")
    -- table.remove(array, 3)
    table.sort(array)
    -- for i=1,#array,1 do
    --     print(array[i])
    -- end
    -- table.foreachi(array, t_print)
    print(table.maxn(array))


end

function t_cjson()
    package.cpath = "/Users/Bran/.luarocks/lib/lua/5.3/?.so;"..package.cpath
    print(package.cpath)
    local cjson = require "cjson"
    -- local cjson2 = require cjson.new()
    local obj = {
        name = "dennis",
        age = 18
    }
    local jsonstr = cjson.encode(obj)
    print(jsonstr)

    local jsonStr = '{"name":"dennis","age":18}';
    local luaObj = cjson.decode(jsonStr);
    print(luaObj['name'],luaObj.age)
    print(luaObj['age'], luaObj.name)
end




-- t_cjson()
t_table3()
-- t_table2()
-- t_table()
-- t_array()
-- t_operator()
-- t_for()
-- t_if()
-- sfind("www.runoob.com", "runoob.")
-- print(add(3,4,5,6,7,9))