name = 'main'
n = 100
for i in range(1, n + 1):
    t_name = '.\\src\\'+ name +str(i) + '.c'
    print(t_name)
    with open(t_name, 'w') as f:
        f.write('#include <stdio.h>\n\nint main(int argc, char *argv[]) {  \n\tprintf("Hello %s");\n\treturn 0; \n}' % (name +str(i)).title())