function A = group(N)

A = 0:N-1;
M = N;
while M>2
    B = [];
    if mod(M,5) == 0
        for k = 1:M:N
            B = [B A(k:5:k-1+M) A(k+1:5:k-1+M) A(k+2:5:k-1+M) A(k+3:5:k-1+M) A(k+4:5:k-1+M)];
        end
        M = M/5;
    elseif mod(M,3) == 0
        for k = 1:M:N
            B = [B A(k:3:k-1+M) A(k+1:3:k-1+M) A(k+2:3:k-1+M)];
        end
        M = M/3;
    else
        for k = 1:M:N
            B = [B A(k:2:k-1+M) A(k+1:2:k-1+M)];
        end
        M = M/2;
    end
    A = B;
end

end