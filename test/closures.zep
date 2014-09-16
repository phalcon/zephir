
namespace Test;

class Closures
{
	public function simple1()
	{
		return function(){ };
	}

	public function simple2()
	{
		return function() {

		};
	}

	public function simple3()
	{
		return function(param1) {

		};
	}

	public function simple4()
	{
		return function(var param1) {

		};
	}

	public function simple5()
	{
		return function(var param1) {
			return function() {
				return 1;
			};
		};
	}
}
