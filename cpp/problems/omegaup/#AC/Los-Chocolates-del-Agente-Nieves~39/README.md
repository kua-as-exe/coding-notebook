https://omegaup.com/arena/problem/chocolates/#problems

$$
\begin{split}
dias = n-(fin-ini)
\end{split}
$$

$$
f(ini, fin) = \left\{\begin{array}{l}
    \begin{array}{r}
        n*P_{ini}&si&ini =fin 
    \end{array}\\
    max \begin{cases}
        f(ini+1, fin) + P_{ini}*dias \\
        f(ini, fin-1) + P_{fin}*dias
    \end{cases}
\end{array}
\right.
$$
