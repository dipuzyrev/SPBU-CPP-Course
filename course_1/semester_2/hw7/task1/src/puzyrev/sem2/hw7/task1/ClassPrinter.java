package puzyrev.sem2.hw7.task1;

import java.lang.reflect.*;

public class ClassPrinter {
    private static String testField1;
    private int testField2;

    public String printClass(Class clazz) {
        return getClassInfo(clazz, "    ");
    }

    private String getClassInfo(Class clazz, String tab) {
        String classInfo = "";
        classInfo += getClassSignature(clazz) + "{\n";

        Field[] fields = clazz.getDeclaredFields();
        for (int i = 0; i < fields.length; i++) {
            if (!isNumber(fields[i].getName().replace("this$", ""))) {
                classInfo += "    " + getFieldSignature(clazz, fields[i]) + "\n";
            }
        }

        Constructor[] constructors = clazz.getDeclaredConstructors();
        classInfo += (constructors.length != 0) ? "\n" : "";
        for (int i = 0; i < constructors.length; i++) {
            classInfo += "    " + getConstructorSignature(clazz, constructors[i]) + "\n";
        }

        Method[] methods = clazz.getDeclaredMethods();
        classInfo += (constructors.length != 0) ? "\n" : "";
        for (int i = 0; i < methods.length; i++) {
            classInfo += "    " + getMethodSignature(clazz, methods[i]) + "\n";
        }

        Class[] classes = clazz.getDeclaredClasses();
        classInfo += (constructors.length != 0) ? "\n" : "";
        for (int i = 0; i < classes.length; i++) {
            classInfo += getClassInfo(classes[i], "    ");
        }

        classInfo += "}\n";
        return classInfo;
    }

    private String getClassSignature(Class clazz) {
        String result = "";
        String modifiers = Modifier.toString(clazz.getModifiers()) + " ";

        if (clazz.isInterface()) {
            result += modifiers.replace("abstract ", "");
        } else {
            result += modifiers;
            result += "class ";
        }

        result += clazz.getSimpleName();
        result += " ";

        if ((clazz.getSuperclass() != null) && !clazz.getSuperclass().equals(Object.class)) {
            result += "extends " + clazz.getSuperclass().getSimpleName() + " ";
        }

        if (clazz.getInterfaces().length != 0) {
            Class[] interfaces = clazz.getInterfaces();
            result += "implements " + interfaces[0].getSimpleName();

            for (int i = 1; i < interfaces.length; i++) {
                result += ", " + interfaces[i].getSimpleName();
            }

            result += " ";
        }

        return result;
    }

    private String getFieldSignature(Class clazz, Field field) {
        String result = "";
        String modifiers = Modifier.toString(field.getModifiers()) + " ";

        if (clazz.isInterface()) {
            result += modifiers.replace("static ", "");
        } else {
            result += modifiers;
        }

        result += field.getType().getSimpleName() + " " + field.getName() + ";";
        return result;
    }

    private String getConstructorSignature(Class clazz, Constructor constructor) {
        String result = "";
        result += Modifier.toString(constructor.getModifiers()) + " " + clazz.getSimpleName() + "(";
        result += getParametersList(constructor.getParameters()) + ");";
        return result;
    }

    private String getMethodSignature(Class clazz, Method method) {
        String result = "";
        String modifiers = Modifier.toString(method.getModifiers()) + " ";

        if (clazz.isInterface()) {
            result += modifiers.replace("abstract ", "");
        } else {
            result += modifiers;
        }

        result += method.getReturnType().getSimpleName() + " ";
        result += method.getName() + "(";
        result += getParametersList(method.getParameters()) + ");";
        return result;
    }

    private String getParametersList(Parameter[] parameters) {
        String result = "";

        if (parameters.length == 0) {
            return "";
        }

        result += parameters[0].getType().getSimpleName() + " ";
        result += parameters[0].getName();

        for (int i = 1; i < parameters.length; i++) {
            result += ", " + parameters[i].getType().getSimpleName() + " ";
            result += parameters[i].getName();
        }

        return result;
    }

    private boolean isNumber(String string) {
        try {
            Integer.parseInt(string);
        } catch (Exception e) {
            return false;
        }

        return true;
    }
}