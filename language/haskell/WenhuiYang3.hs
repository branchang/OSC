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

printPic :: [String] -> IO ()
printPic pic = putStr (concat (map (++"\n") pic))
xx :: Int
yy :: Int
xx = 0
yy = 0

above, aside :: Picture -> Picture -> Picture
above = (++) -- xx+=1
aside = zipWith (++) --yy+=1
--aside = (++)

black :: [[Char]]
black = [" # "]
white :: [[Char]]
white = [" . "]

chessboard :: Int -> Picture -> Picture
chessboard n pic 
                  |pic == white     = chessBoard  n
				  |pic == black     = chessBoard' n

judgment_black_or_white :: Int -> Int -> Picture
judgment_black_or_white x y
            | x == y = black
            | x /= y = white

blackLine :: Int -> Int -> Int -> Picture
blackLine n x y 
           |n == 1  = judgment_black_or_white x y
		   |n >  1  = aside  (judgment_black_or_white xx yy)  (whiteLine (n-1) xx yy)

whiteLine :: Int -> Int -> Int -> Picture		   
whiteLine n x y  
           |n == 1  = judgment_black_or_white xx yy --xx++ 
 		   |n >  1  = aside  (judgment_black_or_white xx yy) (blackLine (n-1) xx yy), yy=yy+1 --yy++

blackChess :: Int -> Int -> Int -> Int -> Picture
blackChess n m x y 
               | n==1  = (blackLine m ) --xx++
			   | n> 1  = above (blackLine m xx yy)  (whiteChess (n-1) m) -- yy++

whiteChess :: Int -> Int -> Int-> Int-> Picture
whiteChess n m x y 
               | n==1  = (whiteLine m )
           	   | n >1  = above (whiteLine m )  (blackChess (n-1) m)

--chessBoard :: Int ->  Picture			   
--chessBoard n = whiteChess n n			   
			   
chessBoard' :: Int ->  Picture
chessBoard'	n  = blackChess n n xx yy

chessBoardline :: Int -> IO() 
chessBoardline n = printPic (chessBoard' n  )


		
			   
			   
