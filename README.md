# HelperApp

1. Open MainApp.sln in VS2019

1. Set PackagingProject as the startup project

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
