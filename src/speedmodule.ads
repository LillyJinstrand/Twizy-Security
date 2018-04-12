with types; 
use types;

package speedModule 
    with SPARK_Mode
is
   function speedtest(S : in Speed) return Boolean with
     Post => (if speedtest'Result then S >= 0.0 and S <= 5.0) and
    (if not speedtest'Result then S< 0.0 or S > 5.0),
     Global => null;

end speedModule;
