### Documentation

[Linux password](https://www.oreilly.com/library/view/practical-unix-and/0596003234/ch04s03.html)

### External
```
MAKEFILE Makefile 
C        brute.c
```

### Exploit
1. `cat /etc/passwd | grep flag01`
   ```bash
   flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
   ```

2. `make && ./brute 42hDRfypTqqnw`
   ```bash
   target: 42hDRfypTqqnw - salt: 42
   find - pass: abcdefg
   ```

3. `su flag01` pass : abcdefg
   ```bash
   getflag
   ```
