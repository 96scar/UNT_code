----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:20:31 10/26/2016 
-- Design Name: 
-- Module Name:    mux8to1 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity mux8to1 is
    Port ( A : in STD_LOGIC;
			  S : in  STD_LOGIC_VECTOR (2 downto 0);
           F : out  STD_LOGIC);
end mux8to1;

architecture Behavioral of mux8to1 is

begin
	process(A, S)
	begin
		case S is
			WHEN "000" => F <= A;
			WHEN "001" => F <= (NOT A);
			WHEN "010" => F <= A;
			WHEN "011" => F <= '1';
			WHEN "100" => F <= '0';
			WHEN "101" => F <= (NOT A);
			WHEN "110" => F <= '0';
			WHEN "111" => F <= A;
			WHEN OTHERS => F <= '0';
		end case;
	end process;



end Behavioral;

