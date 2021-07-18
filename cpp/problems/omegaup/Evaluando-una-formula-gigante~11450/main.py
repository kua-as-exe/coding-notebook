[x, y, z] = list(map(float, input().split()))

print((((2*x+y)/z)*(pow(y, 3)-z))/((x+2*y+3*z)/(z-2*y-3*x)+pow(x,2)+pow(z,2)))