array = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
i = 0
while i < array.length do 
    puts "a[#{i}], a[#{i+1}], a[#{i+2}], a[#{i+3}]"
    i=i+4;
end

class Tree
    attr_accessor :family_tree
    def initialize(family={})
        @family_tree = family
    end

    def visit_all(&block)
        #visit family.each_key
        #family.each {|key,value| visit_all &block}
  #      &block.each {|key,value| visit_all value}
    end

    def visit(&block)
        block.call self
    end
end

#ruby_tree = Tree.new("Ruby", [Tree.new("Reia"), Tree.new("MacRuby")] )
ruby_tree = Tree.new({'grandpa' => { 'dad' => {'child 1' => {}, 'child 2' => {} }, 'uncle' => {'child 3' => {}, 'child 4' => {} } } })


puts "visiting  entire tree"
#ruby_tree.visit_all 



#3 question

filename = gets 
find_str = gets
file = File.open(filename.strip)
num =0
file.each_line do |line|
    if /#{find_str.strip}/.match(line) != nil then
        puts "#{num} #{line}"
    end
    num=num+1
end

