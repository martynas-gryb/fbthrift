/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */


import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;

import com.facebook.thrift.lite.*;
import com.facebook.thrift.lite.protocol.*;


public class Module {

    public enum EventType {
      ComplexUnion;
    }

    public static final ThriftProperty<Long> ComplexUnion_intValue =
        new ThriftProperty<Long>("intValue", TType.I64, (short)1);
    public static final ThriftProperty<String> ComplexUnion_stringValue =
        new ThriftProperty<String>("stringValue", TType.STRING, (short)2);
    public static final ThriftProperty<List<Long>> ComplexUnion_intListValue =
        new ThriftProperty<List<Long>>("intListValue", TType.LIST, (short)3);
    public static final ThriftProperty<List<String>> ComplexUnion_stringListValue =
        new ThriftProperty<List<String>>("stringListValue", TType.LIST, (short)4);
    
}
