### Documentation
[LD_PRELOAD](https://repo.zenk-security.com/Techniques%20d.attaques%20%20.%20%20Failles/Quelques%20astuces%20avec%20LD_PRELOAD.pdf)

### External
```
c   lib.c
```

### Process
. `./send level13 ./level13/Ressources/lib.c`

2. `gcc -shared lib.c -o lib.so`

3. `export LD_PRELOAD=$(pwd)/lib.so`

4. `id`
    ```
    uid=4242 ...
    ```

5. `cp level13 notlevel13`

6. `./notlevel13`
