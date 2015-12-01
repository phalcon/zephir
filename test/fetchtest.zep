
/**
 * Fetch statement tests
 */

namespace Test;

class FetchTest
{

	protected values { set, get };

	public function testFetchArray1(var a, var b)
	{
		var c;
		return fetch c, a[b];
	}

	public function testFetchArray2(var a, int b)
	{
		var c;
		return fetch c, a[b];
	}

	public function testFetchArray3(var a, string b)
	{
		var c;
		return fetch c, a[b];
	}

	public function testFetchObject1(var a, var b)
	{
		var c;
		return fetch c, a->{b};
	}

	public function testFetchPost(var b)
	{
		var c;
		if !fetch c, _POST[b] {
			return false;
		}

		return c;
	}

	public function hasValue(string name) -> boolean
    {
        // Check if there is a post value for the item
        if isset _POST[name] {
            return true;
        } else {
            // Check if there is a predefined value for it
            if isset this->values[name] {
                return true;
            }
        }

        return false;
    }

	public function getValue(string name)
    {
        var value;

        // Check if there is a predefined value for it
        if !fetch value, _POST[name] {
            // Check if there is a post value for the item
            if !fetch value, this->values[name] {
                return null;
            }
        }

        return value;
    }
}