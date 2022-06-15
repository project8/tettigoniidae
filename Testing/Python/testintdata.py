
"""
  testintdata.py
 
   Created on: Jun 14, 2022
       Author: A. Ziegler
"""

__all__ = []

import _tettigoniidae

class TestIntData(_tettigoniidae.data.IntData):
    
    def __init__(self,):
        super().__init__()

def main(args):
    
    test_data = TestIntData()
    
    # Should print the default values.
    print(f'The first value is {test_data.IValue1}. The second value is {test_data.IValue2}.')

    value1 = -69
    value2 = 420

    test_data.IValue1 = value1
    test_data.IValue2 = value2

    # Should print the new values.
    print(f'Now the first value is {test_data.IValue1}. Now the second value is {test_data.IValue2}.')

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
