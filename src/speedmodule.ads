package speedModule 
    with SPARK_Mode
is
   type Speed is delta 0.1 range -80.0 .. 80.0;
   function speedtest(S : in Speed) return Boolean with
     Post => (if speedtest'Result then S >= 0.0 and then S <= 5.0) and
    (if not speedtest'Result then S< 0.0 and then S > 5.0),
     Global => null;

end speedModule;
