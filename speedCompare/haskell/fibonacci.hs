main :: IO ()
main = do
  putStrLn "Enter a number: "
  n <- getLine
  let num = read n :: Int
  putStrLn ("The " ++ n ++ "th fibonacci number is: " ++ show (fib num))

fibAcc n n1 n2
  | n == 0 = n1
  | n == 1 = n2
  | otherwise = fibAcc (n - 1) n2 (n1 + n2)

fib n = fibAcc n 0 1
