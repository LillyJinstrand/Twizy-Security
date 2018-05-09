with Types;
use Types;

package Mathutil with SPARK_Mode => On is

	function ArcTan(Y : FloatingNumber; X : FloatingNumber) return FloatingNumber
	  with
	  Global => null,
	  Pre => X /= 0.0 and then Y /= 0.0,
	  Post => ArcTan'Result <= 180.0 and then ArcTan'Result >= (-180.0);

	function Sin(X : FloatingNumber) return FloatingNumber
	  with
	  Post => Sin'Result >= -1.0 and Sin'Result <= 1.0,
	  Global => null;

	function Cos(X : FloatingNumber) return FloatingNumber
	  with
	  Post => Cos'Result >= -1.0 and Cos'Result <= 1.0,
	  Global => null;

	function Tan(X : FloatingNumber) return FloatingNumber
	  with
	  Global => null;

	function Sin_r(X : FloatingNumber) return FloatingNumber
	  with
	  Post => Sin_r'Result >= -1.0 and Sin_r'Result <= 1.0,
	  Global => null;

	function Cos_r(X : FloatingNumber) return FloatingNumber
	  with
	  Post => Cos_r'Result >= -1.0 and Cos_r'Result <= 1.0,
	  Global => null;

	function Tan_r(X : FloatingNumber) return FloatingNumber
	  with
	  Global => null;

	function Sqrt(X : FloatingNumber) return FloatingNumber
	  with
	  Global => null,
	  Pre => X > 0.0,
	  Post => Sqrt'Result <= X and then Sqrt'Result > 0.0;

end Mathutil;
