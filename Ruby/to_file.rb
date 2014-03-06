module ToFile
    def filename
        "object_#{self.object_id}.txt"
    end
    
    def to_f 
        File.open(filename, 'w') {|f| f.write(to_s)}
    end
end

module FromFile
    def from_f
        a = File.read(filename_s)
        puts a
    end
end

class Person
    include ToFile 
    include FromFile
    attr_accessor :name

    def initialize(name)
        @name = name 
    end

    def to_s 
        name 
    end

    def filename_s
        name 
    end
end

Person.new('matz').to_f
Person.new('matz2').from_f
