set.seed(42)

beta_0 <- -0.05
beta_1 <- 0.35
x <- rnorm(100)
e <- rnorm(100)
y <- beta_0 + beta_1 * x
y <- y + e

cat(x, file = 'x.txt', sep = '\n')
cat(y, file = 'y.txt', sep = '\n')

res <- summary(lm(y ~ x))
