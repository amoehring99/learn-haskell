import System.Environment

main :: IO ()
main = do
  args <- getArgs
  let num = read (head args) :: Int
  putStrLn ("The " ++ show num ++ "th fibonacci number is:\n" ++ show (fib num))

fibAcc n n1 n2
  | n == 0 = n1
  | n == 1 = n2
  | otherwise = fibAcc (n - 1) n2 (n1 + n2)

fib n = fibAcc n 0 1