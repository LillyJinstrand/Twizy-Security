package types is

   type FloatingNumber is digits 12;
   subtype Speed is FloatingNumber range -80.0 .. 80.0;

end types;
