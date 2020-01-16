file = io.open("test.lua", "r")
io.input(file)
print(io.read())
io.close(file)



file = io.open("test.lua", "a")
io.output(file)
io.write("-- test.lua 文本末尾注释")
io.close(file)
