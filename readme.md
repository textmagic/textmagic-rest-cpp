## Synopsis

TextMagic API C++ wrapper will save you a lot of time, as it includes all the necessary API commands and tests. It will just take you a few seconds to download it from GitHub and install it into your own app or software. After installation, you’ll then be able to send text messages.

<!---
sms api for C++
C++ api to send sms
C++ sms api
send sms from C++
C++ send sms messages
C++ library send sms messages
-->

## Code Example
```
#include <iostream>  
#include <textmagic.h>

...
 
Textmagic::Rest::RequestData vars;  
Textmagic::Client tm("USERNAME", "API_KEY");  
const char* kContactId = "12345";  
Textmagic::ContactModel contact = tm.Contacts().get(kContactId, vars);  
if (tm.Contacts().isError){  
   // error handler
} else {  
   // use contact 
}  
```

## Installation
To make a static link library, run the following command:
   ``` make lib ```
If you want to try our examples, run the following command:
   ``` make all ```
    
## Requirements
The C++ wrapper for TextMagic API has the following requirements:
gcc compiler v4.2.1 or higher

## API Reference
* https://www.textmagic.com/docs/api/cpp/
* https://rest.textmagic.com/api/v2/doc

## Examples
To run one of examples please use following commands:
```
cd PROJECT_DIR
make contacts_example
bin/contacts_example USERNAME API_KEY
```

## Contributors
* https://github.com/dmitry-textmagic
* https://github.com/kuzinmv
* https://github.com/pvclever


## License

The library is available as open source under the terms of the [MIT License](http://opensource.org/licenses/MIT).