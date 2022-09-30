### Documentation
*None*

### External
```
C  reverse.c
```

### Exploit
1. `./level token`
   ```
   tpmhr
   ```

2. `./send level09 reverse.c`

3. `gcc reverse.c -o reverse`

3. `./reverse $(cat token)`
   ```
   f3iji1ju5yuevaus41q1afiuq
   ```

4. `su flag09` pass : f3iji1ju5yuevaus41q1afiuq
   ```bash
   getflag
   ```