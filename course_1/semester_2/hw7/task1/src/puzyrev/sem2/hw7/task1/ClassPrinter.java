package puzyrev.sem2.hw7.task1;

import java.lang.reflect.*;

/**
 * Printing internal class structure.
 */
public class ClassPrinter {

    /**
     * Get class structure.
     * @param clazz class to scanning
     * @return class structure in string
     */
    public String printClass(Class clazz) {
        StringBuilder result = new StringBuilder();
        getClassInfo(result, clazz, "    ");
        return result.toString();
    }

    private void getClassInfo(StringBuilder builder, Class clazz, String tab) {
        getClassSignature(builder, clazz);
        builder.append("{\n");

        Field[] fields = clazz.getDeclaredFields();
        for (int i = 0; i < fields.length; i++) {
            if (!isNumber(fields[i].getName().replace("this$", ""))) {
                builder.append("    ");
                getFieldSignature(builder, clazz, fields[i]);
                builder.append("\n");
            }
        }

        Constructor[] constructors = clazz.getDeclaredConstructors();
        if(constructors.length != 0) {
            builder.append("\n");
        }

        for (int i = 0; i < constructors.length; i++) {
            builder.append(tab);
            getConstructorSignature(builder, clazz, constructors[i]);
            builder.append("\n");
        }

        Method[] methods = clazz.getDeclaredMethods();
        if (constructors.length != 0) {
            builder.append("\n");
        }

        for (int i = 0; i < methods.length; i++) {
            builder.append(tab);
            getMethodSignature(builder, clazz, methods[i]);
            builder.append("\n");
        }

        Class[] classes = clazz.getDeclaredClasses();
        if (constructors.length != 0) {
            builder.append("\n");
        }

        for (int i = 0; i < classes.length; i++) {
            getClassInfo(builder, classes[i], tab);
        }

        builder.append("{\n");
    }

    private void getClassSignature(StringBuilder builder, Class clazz) {
        String modifiers = Modifier.toString(clazz.getModifiers()) + " ";

        if (clazz.isInterface()) {
            builder.append(modifiers.replace("abstract ", ""));
        } else {
            builder.append(modifiers);
            builder.append("class");
        }

        builder.append(clazz.getSimpleName());
        builder.append(" ");

        if ((clazz.getSuperclass() != null) && !clazz.getSuperclass().equals(Object.class)) {
            builder.append("extends ");
            builder.append(clazz.getSuperclass().getSimpleName());
            builder.append(" ");
        }

        if (clazz.getInterfaces().length != 0) {
            Class[] interfaces = clazz.getInterfaces();
            builder.append("implements ");
            builder.append(interfaces[0].getSimpleName());

            for (int i = 1; i < interfaces.length; i++) {
                builder.append(", ");
                builder.append(interfaces[i].getSimpleName());
            }

            builder.append(" ");
        }
    }

    private void getFieldSignature(StringBuilder builder, Class clazz, Field field) {
        String modifiers = Modifier.toString(field.getModifiers()) + " ";

        if (clazz.isInterface()) {
            builder.append(modifiers.replace("static ", ""));
        } else {
            builder.append(modifiers);
        }

        builder.append(field.getType().getSimpleName());
        builder.append(" ");
        builder.append(field.getName());
        builder.append(";");
    }

    private void getConstructorSignature(StringBuilder builder, Class clazz, Constructor constructor) {
        builder.append(Modifier.toString(constructor.getModifiers()));
        builder.append(" ");
        builder.append(clazz.getSimpleName());
        builder.append("(");
        builder.append(constructor.getParameters());
        builder.append(");");
    }

    private void getMethodSignature(StringBuilder builder, Class clazz, Method method) {
        String modifiers = Modifier.toString(method.getModifiers()) + " ";

        if (clazz.isInterface()) {
            builder.append(modifiers.replace("abstract ", ""));
        } else {
            builder.append(modifiers);
        }

        builder.append(method.getReturnType().getSimpleName());
        builder.append(" ");
        builder.append(method.getName());
        builder.append("(");
        getParametersList(builder, method.getParameters());
        builder.append(");");
    }

    private void getParametersList(StringBuilder builder, Parameter[] parameters) {
        if (parameters.length == 0) {
            return;
        }

        builder.append(parameters[0].getType().getSimpleName());
        builder.append(" ");
        builder.append(parameters[0].getName());

        for (int i = 1; i < parameters.length; i++) {
            builder.append(", ");
            builder.append(parameters[i].getType().getSimpleName());
            builder.append(" ");
            builder.append(parameters[i].getName());
        }
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