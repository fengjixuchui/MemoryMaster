# MemoryMaster

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

Memory master is a helper library, which you can use to boost development speed of your projects!

  - No additional dependencies
  - Easy to use

# Internal and external feautures

### Installing

Just add .lib file into your libraries path and *.h files into your headers path

# Usage example
#### Signature scanning
```cpp
MemoryMaster::SigFinder finder = MemoryMaster::SigFinder("client.dll");

void* localPlayer = finder.Find(
	"\x48\x8B\x15\xB4\x10\x1A\x02\x48\x8D\x05\xB5\x63\x1F\x01\x00\x00\x00\x00\x00\x00\x00\x48\x85\xD2\x74\x0C",
	"xxxxxxxxxxxxxx???????xxxxx"
);

// now we have pointer to localPlayer!
```

#### DLL Injection
```cpp
MemoryMaster::InjectStatus status = MemoryMaster::External::Injector::InjectDLL(".\\mydll.dll", "csgo.exe");

if(status == MemoryMaster::InjectStatus::SUCCESS) {
    // dll injected!    
}

```

### Getting base address of module
```cpp
MODULE exeBase;
MemoryMaster::WinUtils::GetModule("csgo.exe", &exeBase);

printf("csgo.exe address = %p\n", exeBase.base);
printf("csgo.exe size = %i\n", exeBase.size);

```