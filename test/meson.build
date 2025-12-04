
gtest = subproject('gtest')

gtest_dep = gtest.get_variable('gtest_dep')
gmock_dep = gtest.get_variable('gmock_dep')
gtest_main_dep = gtest.get_variable('gtest_main_dep')

tests = [
  'point',
  ]

foreach t : tests
  e = executable(
    t + '_test',
    [t + '_tests.cpp'],
    dependencies: [
      gtest_dep,
      gtest_main_dep,
      gmock_dep,
      adventUtility_dep],
    )

  test(t + ' test', e)
endforeach

