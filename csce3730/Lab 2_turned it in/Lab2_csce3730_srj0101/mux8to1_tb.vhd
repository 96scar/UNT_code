--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   10:56:34 10/26/2016
-- Design Name:   
-- Module Name:   C:/Users/srj0101/Desktop/Lab2_ScarlettJones/Lab2_csce3730_srj0101/mux8to1_tb.vhd
-- Project Name:  Lab2_csce3730_srj0101
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: mux8to1
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY mux8to1_tb IS
END mux8to1_tb;
 
ARCHITECTURE behavior OF mux8to1_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT mux8to1
    PORT(
         A : IN  std_logic;
         S : IN  std_logic_vector(2 downto 0);
         F : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal S : std_logic_vector(2 downto 0) := (others => '0');

 	--Outputs
   signal F : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 --  constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mux8to1 PORT MAP (
          A => A,
          S => S,
          F => F
        );

   -- Clock process definitions
 --  <clock>_process :process
 --  begin
--		<clock> <= '0';
--		wait for <clock>_period/2;
--		<clock> <= '1';
	--	wait for <clock>_period/2;
  -- end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
   --   wait for 100 ns;	

  --    wait for <clock>_period*10;

      -- insert stimulus here 
		
A <= '0'; S(2) <= '0'; S(1) <= '0'; S(0) <= '0';
wait for 10 ns;

A <= '0'; S(2) <= '0'; S(1) <= '0'; S(0) <= '1';
wait for 10 ns;

A <= '0'; S(2) <= '0'; S(1) <= '1'; S(0) <= '0';
wait for 10 ns;

A <= '0'; S(2) <= '0'; S(1) <= '1'; S(0) <= '1';
wait for 10 ns;

A <= '0'; S(2) <= '1'; S(1) <= '0'; S(0) <= '0';
wait for 10 ns;

A <= '0'; S(2) <= '1'; S(1) <= '0'; S(0) <= '1';
wait for 10 ns;

A <= '0'; S(2) <= '1'; S(1) <= '1'; S(0) <= '0';
wait for 10 ns;

A <= '0'; S(2) <= '1'; S(1) <= '1'; S(0) <= '1';
wait for 10 ns;

A <= '1'; S(2) <= '0'; S(1) <= '0'; S(0) <= '0';
wait for 10 ns;

A <= '1'; S(2) <= '0'; S(1) <= '0'; S(0) <= '1';
wait for 10 ns;

A <= '1'; S(2) <= '0'; S(1) <= '1'; S(0) <= '0';
wait for 10 ns;

A <= '1'; S(2) <= '0'; S(1) <= '1'; S(0) <= '1';
wait for 10 ns;

A <= '1'; S(2) <= '1'; S(1) <= '0'; S(0) <= '0';
wait for 10 ns;

A <= '1'; S(2) <= '1'; S(1) <= '0'; S(0) <= '1';
wait for 10 ns;

A <= '1'; S(2) <= '1'; S(1) <= '1'; S(0) <= '0';
wait for 10 ns;

A <= '1'; S(2) <= '1'; S(1) <= '1'; S(0) <= '1';
wait for 10 ns;
		

      wait;
   end process;

END;
