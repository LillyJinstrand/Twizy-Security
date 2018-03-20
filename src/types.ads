package types is

   -- 9 digits let's us represent 10^7m with cm accuracy
   type FloatingNumber is digits 9;
   subtype Speed is FloatingNumber range -80.0 .. 80.0;

--   procedure DivIsMulInverse(A : FloatingNumber; B : FloatingNumber; C : FloatingNumber)
--	 with
--	 Ghost,
--	 Global => null,
--	 Pre => A >= B / C,
--	 Post => A * C < B;

end types;
