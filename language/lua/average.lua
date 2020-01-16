function average(...)
    result = 0
    local arg = {...}
    for i,v in ipairs(arg) do
        result = result + v
    end
    print("total pararm "..#arg.." num.")
    return result/#arg
end

print("average", average(10,3,4,5,693,28347))
