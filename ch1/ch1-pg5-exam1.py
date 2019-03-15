import math;

r = float(input());
h = float(input());

s1 = 2 * math.pi * r * h;
s2 = math.pi * pow(r, 2);

area = s1 + 2 * s2;
print('Area = %.3f' %  area);
