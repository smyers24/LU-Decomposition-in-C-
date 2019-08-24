m1=2;
m2=1;
m3=1; 
g=10;
kk=2;
a = [3*kk, -2*kk, 0; -2*kk, 3*kk, -kk; 0, -kk, kk];
b = [m1*g; m2*g; m3*g];
n=input('Please enter the dimensions of the matrix\n');

    %LU decomposition
    for k=1:n-1
        for i = k+1:n
            factor = a(i,k)/a(k,k);
            a(i,k) = factor;
            for j= k+1:n
                a(i,j) = a(i,j) - (factor * a(k,j));
            end
        end
    end
    
    %inverse 
    for i=1:n
        for j=1:n
            if i == j
                b(j) = 1;
            else b(j) = 0;
            end
        end
        %forward substitution
    for i=2:n
        sum = b(i);
        for j=1:i-1
            sum = sum - (a(i,j)*b(j));
        end
        b(i) = sum;
    end

%backward substitution
	x(n) = b(n) / a(n,n);
        for i=n:-1:1
            sum=0;
               for j=i+1:n
                sum = sum + (a(i,j) * x(j));
               end
                x(i) = (b(i) - sum)/a(i,i);
        end
        for j=1:n
        for i=1:n
            ai(j,i)=x(j);
        end
        end
    end
    ai = [ai(1,1),ai(1,2),ai(1,3);ai(2,1),ai(2,2),ai(2,3);ai(3,1),ai(3,2),ai(3,3)];

