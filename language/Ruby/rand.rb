puts "ruby file"

prng = Random.new()
i =  prng.rand(1..8)
puts "please input a num"
user_input = gets
j = user_input.to_i
if i > j
    puts "min"
else 
    if i < j
        puts "big"
    else 
        if i == j
            puts "good luck"
        end
    end
end
puts i
#puts user_input
