
console.log('rootbypass.js loaded');

Java.perform(function() {

    // var ClassToHook = Java.use("com.app.<app>.<className>");
    var RootUtil = Java.use("com.app.solydbank.Rootutil");

    // Hook the function => implementation is the function that will override the original function
    RootUtil.isDeviceRooted.implementation = function() {
        console.log("Anti-rooting bypassed!");
        return false;
    };


})


