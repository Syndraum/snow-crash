1. `gdb getflag`

2. `disassemble main`
   ```s
   0x08048afd <+439>:	call   0x80484b0 <getuid@plt>
   ...
   0x08048bb6 <+624>:	cmp    $0xbc6,%eax
   0x08048bbb <+629>:	je     0x8048de5 <main+1183>
   ...
   0x08048de5 <+1183>:	mov    0x804b060,%eax #key
   0x08048dea <+1188>:	mov    %eax,%ebx
   0x08048dec <+1190>:	movl   $0x8049220,(%esp) #str
   0x08048df3 <+1197>:	call   0x8048604 <ft_des>
   ```

3. `break main`

4. `run`

5. `print ft_des(0x8049220, 0x804b060)`

6. `x/s $1`