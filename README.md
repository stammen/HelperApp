# HelperApp

1. Open MainApp.sln in VS2019

1. Set PackagingProject as the startup project

1. Select Debug x86 or x64 as the project configuration

1. Build and run the solution.

1. MainApp will run and launch the HelperApp


#Discussion

The MainApp solution also dynamically adds a file to the package based on the build Platform and Configuration. The following xml was added to the MainApp.vcxproj

```xml
  <ItemGroup>
    <Content Include="$(ProjectDir)..\assets\$(Configuration)\$(PlatformTarget)\*.txt">
      <Link>%(RecursiveDir)%(FileName)%(Extension)</Link>
      <CopyToOutputDirectory>Always</CopyToOutputDirectory>
    </Content>
  </ItemGroup>
```

When you build and run the app, you will see the correct text file is added to the Package. Look in

PackagingProject\bin\{Platform}\{Configuration}\AppX\MainApp

where {Platform} is x86 or x64 and {Configuration} is Debug or Release

You will find .txt file in the folder based on {Platform} and {Configuration}.
