module = {}
module.constant = "this is a contant."
function module.func1()
    io.write(" this is a public func.")
end

local function func2()
    io.write("this is a local func.")
end

function module.func3()
    func2()
end

return module
