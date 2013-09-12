animals = ['lions and', 'tigers and', 'bears', 'on my']
animals.each {|a|puts a}


#使用yield调用block code
class Fixnum
def my_times
    i = self
    while i > 0
        i=i-1
        yield
    end
end
end

3.my_times {puts 'mangy moose'}

#Blocks can also be first-class parameters

def call_block(&block)
    block.call
end

def pass_block(&block)
    call_block(&block)
end

pass_block {puts 'hello, block'}

#block用于提供给我们使用可以传递可执行的代码
#you use blocks to delay execution

execute_at_non {puts 'Beep beep.... time to get up'}
