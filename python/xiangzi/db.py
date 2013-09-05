import sqlite3

conn=sqlite3.connect("test2.db")

curs = conn.cursor()

curs.execute(
        '''
        CREATE TABLE food(
            id      TEXT    PRIMARY KEY,
            num     INT,
            desc    TEXT,
            water   FLOAT
        )
        '''
)

query = 'INSERT INTO food VALUES (1,1,"bran",1000)'
conn.execute(query)
conn.commit()
query = 'INSERT INTO food VALUES (2,2,"biran",1000)'
conn.execute(query)
conn.commit()
conn.close()

