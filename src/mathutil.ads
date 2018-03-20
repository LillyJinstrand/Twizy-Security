with Types;
use Types;

package Mathutil with SPARK_Mode => On is

	function ArcTan(X : FloatingNumber) return FloatingNumber
	  with
	  Global => null,
	  Pre => X /= 0.0;

	function Sqrt(X : FloatingNumber) return FloatingNumber
	  with
	  Global => null,
	  Pre => X > 0.0;

end Mathutil;
