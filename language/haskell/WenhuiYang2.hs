-- Aufgabe 1.1

vollkommen :: Int-> Bool
vollkommen n = n == sum [ i | i <-[1..n-1] , mod n i == 0 ]

-- Aufgabe 1.2
-- a

power :: (Num a, Integral b ) => a -> b -> a
power k n      | n < 0    = error "power : nicht definierter Wert"
               | n == 0   = 1
			   | n == 1   = k
			   | n > 1    = power k (n-1) * k 
		

-- b

power' :: (Num a, Integral b ) => a -> b -> a
power' k n      | n < 0    = error "power : nicht definierter Wert"
                | n == 0   = 1
				| n == 1   = k
				| mod n 2 == 1  = power' k (div(n-1) 2 ) * power' k (div(n-1) 2 ) * k
				| mod n 2 == 0  = power' k (div n 2 ) * power' k (div n 2 )
	
-- Aufgabe 1.3
-- a 

type Picture = [String]
xx :: Int
yy :: Int
xx = 0
yy = 0

printPic :: [String] -> IO ()
printPic pic = putStr (concat (map (++"\n") pic))


above, aside :: Picture -> Picture -> Picture
above = (++)
aside = zipWith (++)

black :: [[Char]]
black = [" # "]
white :: [[Char]]
white = [" . "]

chessboard :: Int -> Picture -> Picture
chessboard n pic 
                  |pic == white     = chessBoard  n
				  |pic == black     = chessBoard' n
blackLine :: Int -> Picture
blackLine n 
           |n == 1  = black
		   |n >  1  = aside  black  (whiteLine (n-1))

whiteLine :: Int -> Picture		   
whiteLine n 
           |n == 1  = white
 		   |n >  1  = aside  white  (blackLine (n-1)); yy =yy+1

blackChess :: Int -> Int -> Picture
blackChess n m  
               | n==1  = (blackLine m )
			   | n> 1  = above (blackLine m )  (whiteChess (n-1) m) 
			   
whiteChess :: Int -> Int -> Picture
whiteChess n m  
               | n==1  = (whiteLine m )
           	   | n >1  = above (whiteLine m )  (blackChess (n-1) m)

chessBoard :: Int ->  Picture			   
chessBoard n = whiteChess n n			   
			   
chessBoard' :: Int ->  Picture
chessBoard'	n = blackChess n n 		   


		
			   
			   
